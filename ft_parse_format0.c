#include "ft_printf.h"

void		ft_parse_format0(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	if (format[parse->i] == '*')
	{
		parse->width.width = va_arg(*ap, int);
		if (parse->width.width < 0)
		{
			parse->neg.width = -parse->width.width;
			parse->neg.val = 1;
		}
		else
			parse->width.val = 1;
		parse->i++;
	}
}
