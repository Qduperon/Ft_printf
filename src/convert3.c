int		ft_S(va_list args, t_form form_struct)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(args, wchar_t *);
}

int		ft_p(va_list args, t_form form_struct)
{
	int					i;
	unsigned long		str;

	i = 0;
	str = va_arg(args, void *);


}

int		ft_C(va_list args, t_form form_struct, char **final)
{
	int			i;
	wchar_t		str;

	i = 0;
	str = va_arg(args, wchar_t);
}
