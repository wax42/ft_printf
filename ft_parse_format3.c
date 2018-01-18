#include "ft_printf.h"

static void	ft_parse_format3_zero(const char *restrict format, p_f *parse)
{
	char *tmp;

	tmp = NULL;
	while (format[parse->i] == '0')
		parse->i++;
	parse->neg.width = ft_atoi(format + parse->i);
	tmp = ft_itoa(parse->neg.width);
	parse->i += ft_strlen(tmp);
	if (!parse->neg.width)
		parse->i--;
	ft_strdel(&tmp);
}

void		ft_parse_format3(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	char *tmp;

	tmp = NULL;
	if (format[parse->i] == '-')
	{
		parse->neg.val = 1;
		while (format[parse->i] == '-')
			parse->i++;
		if (format[parse->i] == '+')
		{
			parse->plus = 1;
			while (format[parse->i] == '+')
				parse->i++;
		}
		if (format[parse->i] == '*')
			parse->neg.width = va_arg(*ap, int);
		else
			ft_parse_format3_zero(format, parse);
	}
}
