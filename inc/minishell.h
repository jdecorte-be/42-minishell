#ifndef MINISHELL_H
# define MINISHELL_H

#include <strings.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <crt_externs.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <dirent.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_redirect
{
	t_list	*infile;
	t_list	*outfile;
	int		infd;
	int		outfd;
	int		open;
}	t_redirect;

typedef struct s_token
{
	char			*cmd;
	t_redirect		redirect;
	struct s_token	*sup_token;
	struct s_token	*sub_token;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	char				*line;
	struct s_redirect	redirect;
	struct s_cmd		*sup_cmd;
	struct s_cmd		*sub_cmd;
	struct s_cmd		*back;
	struct s_cmd		*and;
	struct s_cmd		*or;
}	t_cmd;

typedef struct s_data//  block de cmd  
{
	char	**env;
	int		lastret;
	int		stdin;
	int		stdout;
	int		is_subshell;
	int		is_pipe;
	t_token	*token;
}	t_data;

typedef struct s_tmp
{
	int		i;
	int		i2;
	char	c;
	t_list	*lst;
	void	*tmp;
	char	path[PATH_MAX];
	char	**tab;
	char	*str;
	void	*ptr;
	char	home[PATH_MAX];
}	t_tmp;



char *prompt();
void	sig_handler(int sig);
char *my_getenv(char *name, t_data *data);
int my_setenv(char *name, char *value, t_data *data);
void refresh_env(char **env, t_data *data);
int checkvalid(char *cmd);
int     echo(char **args);
int     pwd();
int     cd(char **args, t_data *d_env);
int     export(char **cmd,t_data *data);
int     unset(char **cmd, t_data *data);
int     printList(t_list *head);

t_list  *list_env(char **env);
char    **listtotab(t_list *lst);
void    env_cmd(t_data *data);
void	*ft_memdel(void *ptr);
void replace_env(char *cmd, t_list *env);

void *ft_realloc(void *str, size_t len);


int	first_pipe(t_data *d_env, char *cmd);
int last_pipe(t_data *d_env, char *cmd);
int	mid_pipe(t_data *d_env, char *cmd);




int subshell(char *line, t_data *data);
void	addspace(char **str);
char	**ft_split2(char *str, char *set);
char	*ft_onespace(char *line);

t_data	*ft_datanew(char	*line);
t_data	*ft_datalast(t_data *data);
void	ft_dataadd_back(t_data **data, t_data *new);

char	**ft_split2(char *str, char *set);
char	*ft_onespace(char *line);
char	*ft_epur_str(char *line);
int		ft_str_isspace(char *str);
void	ft_error(int e);

int		ft_free(char *line);
int	pipex(t_data *d_env, char *cmd);
void	puterror(char *str);
void	*ft_memdel(void *ptr);
int run_cmd(t_data *d_env, char *cmd);
int cmdlexer(char *cmd, t_data *d_env);

char **sort_exp(char **env);

char *tokenize(char *line);
char	*ft_pgross_str(char *line);
char	*ft_epur_str(char *line);
int execute(char **input, t_data *data);





//================================================================

t_cmd	*ft_cmdnew(char	*line);
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);


char	**ft_split2(char *str, char *set);
char	*ft_onespace(char *line);
char	*ft_epur_str(char *line);
int		ft_str_isspace(char *str);

void	ft_creat_tab2(char *str, size_t *end, char *set, int e);
void	ft_count_words2(char *str, size_t *i, char *set);
char	**ft_split3(char *str, char *set);

t_cmd	*ft_creat_cmd(char *line);
char	*ft_pgross_str(char *line);
char	*ft_chdollar(char *line);

char	**ft_split4(char *str, char *set);
char	*ft_chwc(char *line);
char	*ft_wcfile(char *wc, char *path);
t_list	*ft_wcsearch(char *line);

char	*ft_trijoin(char *s1, char *s2, char *s3);
int		ft_exist(char *str, size_t len);
char	*ft_lstmerge(t_list *lst);
char	*ft_woquote(char *line);
char	*ft_replace(char *str, char *search, char *replace);

void	ft_error(int e);
int		ft_free(char *line);
void	ft_free_tab(char **tab);

char	*ft_trijoin1(char *s1, char *s2, char *s3);
char	*ft_trijoin2(char *s1, char *s2, char *s3);
char	*ft_trijoin3(char *s1, char *s2, char *s3);

char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2);
int	pipe_handler(t_data *d_env, char **input, int *i);
void	puterror(char *str);
void	*ft_memdel(void *ptr);
int pipe_is_after(char **input, int i);
int exec(char *cmd, t_data *d_env);
char **sort_exp(char **env);

char *tokenize(char *line);
char	*ft_pgross_str(char *line);
char	*ft_epur_str(char *line);
char	*ft_strjoin2(char const *s1, char const *s2);
int		ft_strncmp2(const char *s1, const char *s2, size_t n);
int		ft_strrcmp2(const char *s1, const char *s2, size_t n);
int print_env(char **env);
void print_exp(t_data *data);
int my_setenv(char *name, char *value, t_data *data);
int splitlen(char **split);
char	*ft_chdir(char *line);
int what_im(char *input);
int exit_cmd(char **s_cmd);
int cmd_sys(t_data *d_env, char *cmd);


t_token	*ft_tokennew(char *newcmd);
t_token	*ft_sub_tokennew(char *newcmd, t_token *sup);
t_token	*ft_tokenlast(t_token *token);
void	ft_tokenadd_back(t_token **atoken, t_token *new);
t_token	*ft_parsing(char *line);
char    *ft_ecrase_q(char *word);
char	*ft_ecrase_p(char *line);
#endif
