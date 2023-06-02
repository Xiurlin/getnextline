#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char	*ft_strcpy(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *) malloc(100 * sizeof(char));
	while (str[i] != c)
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (c == '\0' && s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int main ()
{
	char	*str;
	char	*ret;
	char	c;
	str = "Hola qué pasa";
	c = 'q';
	ret = ft_strchr(str, c);
	str = ft_strcpy (str, c);
	printf("String after |%c| is - |%s|,\nString before |%c| is - |%s|\n", c, ret, c, str);
	return(0);
}


