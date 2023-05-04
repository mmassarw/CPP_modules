#include "File.hpp"

File::File(std::string in): _infile(in){
	_outfile = in + ".replace";
}

File::~File(){
}

void	File::replace(std::string string_to_replace, std::string replacing_string){
	std::ifstream	infile(this->_infile.c_str());
	if (infile.is_open() && infile.good()){
		std::string	content;
		std::string	line;
		while (std::getline(infile, line)){
			content += line;
			content += "\n";
		}
		size_t	pos = content.find(string_to_replace);
		while(pos != std::string::npos && string_to_replace != "") {
			content.erase(pos, string_to_replace.length());
			content.insert(pos, replacing_string);
			pos = content.find(string_to_replace, pos + replacing_string.length());
		}
		std::ofstream	outfile(this->_outfile.c_str());
	if (!outfile.is_open()) {
		std::cerr << "could not open file" << std::endl;
		return;
	}
		outfile << content;
		outfile.close();
		infile.close();
	} else
		std::cout << "could not open file" << std::endl;
	return;
}