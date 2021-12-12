#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

#define SIZE_OF_LINE 12

int	convert_bits_to_decimal(std::string bits, char c)
{
	int	ret;
	int	i;
	
	i = -1;
	ret = 0;
	while (++i < (int)bits.size())
	{
		if (bits[i] == c) 
			ret += pow(2, (int)bits.size() - i - 1);
	}
	return (ret);
}

std::vector<std::string>	read_from_file(std::string filename)
{
	std::string					line;
	std::ifstream				fd(filename);
	std::vector<std::string>	vec;

	fd >> line;
	vec.push_back(line);
	while (!fd.eof())
	{
		fd >> line;
		vec.push_back(line);
	}
	return (vec);
}

char	count(std::vector<std::string> lines, int x)
{
	int count_ones;
	int count_zeros;

	count_ones = 0;
	count_zeros = 0;
	for (std::string line : lines)
	{
		if (line[x] == '1')
			count_ones++;
		else
			count_zeros++;
	}
	if (count_ones >= count_zeros)
		return ('1');
	return ('0');
}

int main(void)
{
	std::vector<std::string>	line;
	std::string					common_bits;
	int							x;

	line = read_from_file("input.txt");
	x = -1;
	while (++x < SIZE_OF_LINE)
		common_bits.push_back(count(line, x));
	std::cout << convert_bits_to_decimal(common_bits, '1') * convert_bits_to_decimal(common_bits, '0') << std::endl;
	return (0);
}
