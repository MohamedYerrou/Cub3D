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

int	handle_file_error(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (message(arg, "Is a directory", FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (message(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !file_cub(arg))
		return (message(arg, "Not a .cub file", FAILURE));
	if (!cub && !file_xpm(arg))
		return (message(arg, "Not an .xpm file", FAILURE));
	return (SUCCESS);
}
