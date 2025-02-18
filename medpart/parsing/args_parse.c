#include "../../cub3d.h"

static bool	file_cub(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 4] != '.') || arg[len - 3] != 'c'
			|| arg[len - 2] != 'u'
			|| arg[len - 1] != 'b')
		return (false);
	return (true);
}

static bool	file_xpm(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 4] != '.') || arg[len - 3] != 'x'
			|| arg[len - 2] != 'p'
			|| arg[len - 1] != 'm')
		return (false);
	return (true);
}

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

int	handle_file_error(t_data *data, char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		message(arg, "Is a directory",1), exit_no_leaks(data, 1);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		message(arg, strerror(errno), 1), exit_no_leaks(data, 1);
	close(fd);
	if (cub && !file_cub(arg))
		message(arg, "Not a .cub file", 1), exit_no_leaks(data, 1);
	if (!cub && !file_xpm(arg))
		message(arg, "Not an .xpm file", 1), exit_no_leaks(data, 1);
	return (SUCCESS);
}
