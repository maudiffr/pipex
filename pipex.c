/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maudiffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:29:02 by maudiffr          #+#    #+#             */
/*   Updated: 2023/06/26 11:27:02 by maudiffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int error)
{
	if (error == 2)
	{
		perror("Error ocurred with opening the pipe");
		exit (2);
	}
	if (error == 3)
	{
		perror("Error with the fork()");
		exit (3);
	}
	if (error == 4)
	{
		perror("Error: Unable to access or execute cmd");
		exit (4);
	}
	if (error == 5 || error == 6)
	{
		if (error == 5)
			perror("Error with file1");
		else if (error == 6)
			perror("Error with file2");
		exit (5);
	}
}

void	exec(char *argv, char **envp)
{
	int		i;
	char	*path_env;
	char	*path_and_cmd;
	char	**all_path;
	char	**cmd;

	i = 0;
	path_env = get_path(envp);
	all_path = ft_split(path_env, ':');
	cmd = ft_split(argv, ' ');
	while (all_path[i])
	{
		path_and_cmd = ft_strjoin(all_path[i], cmd[0]);
		free(path_and_cmd);
		if (access(path_and_cmd, F_OK | X_OK) == 0)
			break ;
		i++;
		if (all_path[i] == NULL)
		{
			ft_free(all_path);
			ft_free(cmd);
			ft_exit(4);
		}
	}
	execve(path_and_cmd, cmd, envp);
}

void	child(int *fd, char **argv, char **envp)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_exit(5);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	exec(argv[2], envp);
}

void	parent(int *fd, char **argv, char **envp)
{
	int	outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_exit(5);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(outfile);
	close(fd[0]);
	exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	id;
	int	wstatus;
	int	status_code;

	if (argc != 5)
		ft_exit2(1);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		ft_exit2(7);
	if (pipe(fd) == -1)
		ft_exit(2);
	id = fork();
	if (id < 0)
		ft_exit(3);
	if (id == 0)
		child(fd, argv, envp);
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		if (status_code != 0)
			return (0);
	}
	parent(fd, argv, envp);
	return (0);
}
