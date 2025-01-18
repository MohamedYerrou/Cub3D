#include "../medpart.h"

static bool	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 4] != '.') || arg[len - 3] != 'c'
			|| arg[len - 2] != 'u'
			|| arg[len - 1] != 'b')
		return (false);
	return (true);
}

static bool	is_xpm_file(char *arg)
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

int	check_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, "Is a directory", FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, "Not a .cub file", FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, "Not an .xpm file", FAILURE));
	return (SUCCESS);
}
