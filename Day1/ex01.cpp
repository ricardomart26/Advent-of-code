#include <iostream>
#include <vector>
#include <fstream>

std::vector<int>	convert_file_to_int_vector(const std::string filename)
{
	std::vector<int>	ret;
	std::ifstream		fd;
	int					num;

	fd.open(filename);
	if (!fd) {
		std::cerr << "File not found" << std::endl;
		exit(1);
	}
	fd >> num;
	ret.push_back(num);
	while (!fd.eof()) {
		fd >> num;
		ret.push_back(num);
	}
	fd.close();
	return (ret);
}

int	measure(void)
{
	std::vector<int>	arr;
	int					bf_sum;
	int					af_sum;
	int					ret;

	arr = convert_file_to_int_vector("input.txt");
	ret = 0;
	bf_sum = (arr[0]) + (arr[1]) + (arr[2]);
	for (auto i = arr.begin() + 2; i < arr.end() - 2; i++)
	{
		af_sum = *i + *(i + 1) + *(i + 2);
		if (bf_sum < af_sum)
			ret++;
		bf_sum = af_sum;
	}
	return (ret);
}

int main(void)
{
	std::cout << "Number of measures: " << measure() << std::endl;
}
