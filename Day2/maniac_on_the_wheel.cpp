#include <iostream>
#include <fstream>

typedef struct s_pos
{
	int	horizontal;
	int	depth;
	int	aim;
}	t_pos;

/*** 1º Parte
 *
 * @commands:	Forward -> Adiciona para a posição horizontal
 * 				Down	-> Aumenta a porfundidade
 * 				Up		-> Diminui a porfundidade
 *
 * 2º Parte:
 *
 * @commands:	Forward -> Adiciona para a posição horizontal, e
 * 						   para a porfundidade multiplica aim * o numero
 * 				Down	-> Aumenta o Aim
 * 				Up		-> Diminui o Aim
 * 
*/

int	get_position()
{
	t_pos			position;
	std::ifstream	fd("input.txt");
	std::string		line;
	int				num;

	position.horizontal = 0;
	position.depth = 0;
	position.aim = 0;
	if (!fd) {
		std::cerr << "File not found!" << std::endl;
	}
	fd >> line >> num;
	while (!fd.eof())
	{
		if (!line.compare("forward")) {
			position.horizontal += num;
			position.depth += position.aim * num;
		}
		else if (!line.compare("down"))
			position.aim += num;
		else if (!line.compare("up"))
			position.aim -= num;
		fd >> line >> num;
	}
	return (position.horizontal * position.depth);
}

int main(void)
{
	std::cout << "Depth * Horizontal = " << get_position() << std::endl;
}
