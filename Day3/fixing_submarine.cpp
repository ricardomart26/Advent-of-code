#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int	convert_string_bits_to_int(std::string bits, char c)
{
	int	ret = 0;
	int	i = 0;
	int	size = bits.size();
	int temp = 0;

	std::cout << size << std::endl;
	while (i < size)
	{
		std::cout << bits[i] << std::endl;
		if (bits[i] == c) {
			temp = size - i;
			std::cout << "temp: " << temp << std::endl;
			ret += pow(2, temp);
			std::cout << "ret: " << ret << std::endl;
		}
		i++;
	}
	return (ret);
}

int main(void)
{
	std::ifstream	fd("input.txt");
	std::string		line[1001];
	int				size_of_one_line;
	
	int	i = 0;
	fd >> line[i++];
	std::cout << line[i - 1] << std::endl;
	while (!fd.eof())
	{
		fd >> line[i++];
		std::cout << line[i - 1] << std::endl;
	}
	int x = 0;
	size_of_one_line = line[0].size();
	std::string		common_bits;
	while (x < size_of_one_line)
	{
		int j = 0;
		int count_ones = 0;
		int count_zeros = 0;
		while (j < 1000)
		{
			if (line[j][x] == '1')
				count_ones += 1;
			else if (line[j][x] == '0')
				count_zeros += 1;
			j++;
		}
		std::cout << "count zeros: " << count_zeros << " count ones: " << count_ones << std::endl;
		if (count_zeros > count_ones)
			common_bits.push_back('0');
		else
			common_bits.push_back('1');
		x++;
		// std::cout << "x: " << common_bits[x - 1] << std::endl;
		
	}
	std::cout << "x: " << x << std::endl;
	int gama = convert_string_bits_to_int(common_bits, '1');
	int epsilon = convert_string_bits_to_int(common_bits, '0');

	std::cout << gama * epsilon << std::endl;

	return (0);
}
