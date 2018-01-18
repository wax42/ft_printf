#include "ft_printf.h"

void	ft_parse_format1(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	char *tmp;

	tmp = NULL;
	if (format[parse->i] == '.')
	{
		parse->precision.val = 1;
		while (format[parse->i] == '.')
			parse->i++;
		if (format[parse->i] == '*')
		{
			parse->precision.width = va_arg(*ap, int);
			parse->i++;
		}
		else if (ft_isdigit(format[parse->i]))
		{
			parse->precision.width = ft_atoi(format + parse->i);
			tmp = ft_itoa(parse->precision.width);
			parse->i += ft_strlen(tmp);
			ft_strdel(&tmp);
		}
	}
}
