/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:38:42 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/07 13:58:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
};

#endif