#include "File.hpp"

int	main(int ac, char** av){
	if (ac != 4) {
		std::cout << "Input is <file_path> <string_to_replace> <replacing_string>" << std::endl;
		return(0);
	} else {
		File	file(av[1]);
		file.replace(av[2], av[3]);
	}
	return (0);
}