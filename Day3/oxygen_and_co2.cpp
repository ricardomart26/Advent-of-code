#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

#define SIZE_OF_LINE 12

int	convert_bits_to_decimal(std::string bits)
{
	int	decimal;
	int	i;

	i = -1;	
	decimal = 0;
	while (++i < (int)bits.size())
	{
		if (bits[i] == '1') {
			decimal += pow(2, bits.size() - i - 1);
		}
	}
	return (decimal);
}

std::vector<std::string>	read_from_file(std::string filename)
{
	std::string					lines;
	std::ifstream				fd(filename);
	std::vector<std::string>	vec;

	vec.reserve(1000);
	fd >> lines;
	vec.push_back(lines);
	while (!fd.eof())
	{
		fd >> lines;
		vec.push_back(lines);
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

void	remove_least_common_bits(std::vector<std::string> &line, int common_bit, int position)
{
	int	i;

	i = 0;
	while (i < (int)line.size())
	{
		if (line[i][position] != (char)common_bit)
			line.erase(line.begin() + i);
		else
			i++;
	}
}

void	remove_most_common_bits(std::vector<std::string> &line, char common_bit, int position)
{
	int	i;

	i = 0;
	while (i < (int)line.size())
	{
		if (line[i][position] == common_bit)
			line.erase(line.begin() + i);
		else
			i++;
	}
}

int main(void)
{
	std::vector<std::string>	lines_of_file;
	std::vector<std::string>	oxygen;
	std::vector<std::string>	co2;
	int							pos;

	lines_of_file = read_from_file("input.txt");
	copy(lines_of_file.begin(), lines_of_file.end(), back_inserter(oxygen));
	copy(lines_of_file.begin(), lines_of_file.end(), back_inserter(co2));
	remove_least_common_bits(oxygen, count(lines_of_file, 0), 0);
	remove_most_common_bits(co2, count(lines_of_file, 0), 0);
	pos = 0;
	while (++pos < SIZE_OF_LINE)
	{
		if (co2.size() > 1)
			remove_most_common_bits(co2, count(co2, pos), pos);
		if (oxygen.size() > 1)
			remove_least_common_bits(oxygen, count(oxygen, pos), pos);
	}
	std::cout << convert_bits_to_decimal(oxygen.front()) * convert_bits_to_decimal(co2.front()) << std::endl;
	return (0);
}
