/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:27:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/15 10:28:20 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGS_H
#define LOGS_H

int		log_error(const char *message);
int		log_warning(const char *message);
int		log_info(const char *message);
int		log_debug(const char *message);
int		log_success(const char *message);

#endif //LOGS_H
