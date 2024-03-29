#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    _months[1] = 31;
    _months[2] = 29;
    _months[3] = 31;
    _months[4] = 30;
    _months[5] = 31;
    _months[6] = 30;
    _months[7] = 31;
    _months[8] = 31;
    _months[9] = 30;
    _months[10] = 31;
    _months[11] = 30;
    _months[12] = 31;
    initData(DATA_FILE);
}

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    _months[1] = 31;
    _months[2] = 29;
    _months[3] = 31;
    _months[4] = 30;
    _months[5] = 31;
    _months[6] = 30;
    _months[7] = 31;
    _months[8] = 31;
    _months[9] = 30;
    _months[10] = 31;
    _months[11] = 30;
    _months[12] = 31;
    initData(dataFile);
}

BitcoinExchange::~BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) {
    *this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & copy) {
    _data = copy._data;
    return (*this);
}

bool BitcoinExchange::calculate_leapyear( int year, int month, int day ) const {
	float y4 = year / 4.0;
	float y100 = year / 100.0;
	float y400 = year / 400.0;

	if (month == 2 && day == 29) {
		if (y4 - floor(y4) == 0.0) {
			if (y100 - floor(y100) == 0.0) {
				if (y400 - floor(y400) != 0.0)
					return false;
				return true;
			}
			if (y400 - floor(y400) != 0.0)
				return true;
			return false;
		}
		return false;
	}
	return true;
}

void BitcoinExchange::initData(const std::string& dataFile) {
    std::ifstream in(dataFile.c_str());
    if (!in.is_open())
        throw std::runtime_error("Could not open file");
    std::string line;
    std::getline(in, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("[date,exchange_rate] missing from file");
    while (std::getline(in, line)) {
        try {
            size_t commaIndex = line.find(",");
            if (commaIndex == std::string::npos)
                throw (std::exception());
            int date = toDate(line.substr(0, commaIndex).c_str());
            float rate = toFloat(line.substr(commaIndex + 1, line.length() - commaIndex - 1));
            _data[date] = rate;
        } catch (const std::exception& e) {
            std::cerr << "Data file line has syntax error [" << line << "]: "
                << e.what() << std::endl;
        }
    }
    in.close();
}

float BitcoinExchange::getValue(int date, float amount) const {
    if (amount < 0)
        throw (std::runtime_error("not a positive number."));
    else if (amount > 1000)
        throw (std::runtime_error("too large a number."));

    std::map<int, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end())
        throw (std::runtime_error("invalid date"));
    if (it->first > date)
        it--;
    if (it->first < 10000000 || it->first > 99999999)
        throw (std::runtime_error("invalid date"));
    return (amount * it->second);
}

bool BitcoinExchange::run(const std::string& inputFile) {
    std::ifstream in(inputFile.c_str());
    if (!in.is_open()) {
        std::cerr << "Error: can't open input file" << std::endl;
        return (false);
    }
    std::string line;
    std::getline(in, line);
    if (line != "date | value")
        throw std::runtime_error("[date | value] missing from file");
    while(std::getline(in, line)) {
        try {
            size_t pipeIndex = line.find("|");
            info cur;
            cur.date = toDate(line.substr(0, pipeIndex).c_str());
            cur.amount = toFloatLimited(line.substr(pipeIndex + 1, line.length() - pipeIndex - 1));
            cur.value = getValue( cur.date, cur.amount);
            std::cout << cur << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    in.close();
    return (true);
}

std::ostream& operator<<(std::ostream& ss, const info& in) {
    int year = in.date / 10000;
    int month = (in.date / 100) % 100;
    int day = in.date % 100;

     std::cout << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-" << std::setw(2) << day
        <<  " => " << in.amount << " = " << in.value;
    return (ss);
}

int BitcoinExchange::toDate(const std::string& dateStr) const {
    int year, month, day;
    if (sscanf(dateStr.c_str(), DATE_FORMAT, &year, &month, &day) != 3)
        throw (std::runtime_error("Bad input => " + dateStr));
    if ( month > 12 || month < 1 || day > _months.find(month)->second || day < 1 || !calculate_leapyear(year, month, day))
        throw (std::runtime_error("Bad input => " + dateStr));
    int date = year * 10000 + month * 100 + day;

    return (date);
}

float   BitcoinExchange::toFloatLimited(const std::string& num) const {
    if (num.find_first_not_of("1234567890+. ") != std::string::npos)
        throw (std::runtime_error("not a positive number."));

    std::istringstream iss(num);
    std::string partBeforeDecimal;
    if (!std::getline(iss, partBeforeDecimal, '.')) {
        partBeforeDecimal = num;
    }

    errno = 0;
    double n = std::atof(num.c_str());

    if (errno || partBeforeDecimal.length() > 4) {
        throw (std::runtime_error("too large a number."));
    }
    return (static_cast<float>(n));
}

float   BitcoinExchange::toFloat(const std::string& num) const {
    if (num.find_first_not_of("1234567890+. ") != std::string::npos)
        throw (std::runtime_error("not a positive number."));

    errno = 0;
    double n = std::atof(num.c_str());

    if (errno) {
        std::cout << n << ", " << errno << std::endl;
        throw (std::runtime_error("too large a number."));
    }
    return (static_cast<float>(n));
}

/*
 *  constructor( string inputFile ):
 *      - check if the input file is valid
 *      - read and store the data file
 *
 *  exchangeAmount( date, amount )
 *      - check if date exists in _data using lower_bound
 *      - return ( amount * found->second )
 *
 *  exchange:
 *      - while file
 *          get line
 *          get date
 *          get amount
 *          final = exchangeAmount( date, amount )
 *          printLog( date, amout, final )
 *
 * toDate( string date ):
 *      - substr the YEAR, MONTH, DATE
 *      - create a map that has the number of days for each month
 *      - check if data is valid
 *          if not throw an exception
 *      - return date YYYYMMDD as an int
 *
 *  readData:
 *      - check if DATA_FILE exists
 *
 *  printLog( int date, float amount, float final ):
 *      - print date << " => " << amount << " = " << final << std::endl
 */
