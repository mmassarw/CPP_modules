#include <fstream>
#include <string>
#include <iostream>

class	File{
	public:
		File(std::string);
		~File();

		void	replace(std::string, std::string);
	private:
		std::string	_infile;
		std::string	_outfile;
};