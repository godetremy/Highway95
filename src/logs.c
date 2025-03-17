/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:27:28 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/15 10:32:36 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	log_error(const char *message)
{
	write(2, "\033[31;1m[ERROR] \033[0m", 19);
	write(2, message, strlen(message));
	write(2, "\n", 1);
	return (1);
}

int	log_warning(const char *message)
{
	write(2, "\033[33;1m[WARNING] \033[0m", 21);
	write(2, message, strlen(message));
	write(2, "\n", 1);
	return (1);
}

int	log_info(const char *message)
{
	write(1, "\033[36;1m[INFO] \033[0m", 18);
	write(1, message, strlen(message));
	write(1, "\n", 1);
	return (1);
}

int	log_debug(const char *message)
{
	write(1, "\033[35;1m[DEBUG] \033[0m", 19);
	write(1, message, strlen(message));
	write(1, "\n", 1);
	return (1);
}

int	log_success(const char *message)
{
	write(1, "\033[32;1m[SUCCESS] \033[0m", 21);
	write(1, message, strlen(message));
	write(1, "\n", 1);
	return (1);
}
