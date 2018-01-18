#include "ft_printf.h"
void	ft_parse_format_all(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	ft_parse_format0(format, parse, ap);
	ft_parse_format1(format, parse, ap);
	ft_parse_format2(format, parse, ap);
	ft_parse_format3(format, parse, ap);
	ft_parse_format4(format, parse, ap);
}

p_f		ft_parse_format(const char *restrict format, int i, va_list *ap)
{
	p_f		parse;
	char	*tmp;

	tmp = NULL;
	parse = ft_init_struct();
	parse.i = i;
	while (!(ft_strchr("hljzsSpdDioOuUxXcC", format[parse.i])))
	{
		ft_parse_format_all(format, &parse, ap);
		if (ft_isdigit(format[parse.i]) && format[parse.i] != '0')
		{
			parse.width.val = 1;
			parse.width.width = ft_atoi(format + parse.i);
			tmp = ft_itoa(parse.width.width);
			parse.i += ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (!(ft_parse_format_pourcent(format, &parse)))
			return (parse);
	}
	ft_parse_format_ltr(format, &parse);
	ft_parse_regle(&parse);
	ft_parse_regle_1(&parse);
	return (parse);
}
