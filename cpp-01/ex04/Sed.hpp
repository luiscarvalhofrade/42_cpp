/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:19:20 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/07 13:43:47 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

std::string replaceString(const std::string& text, const std::string& s1, const std::string& s2);
bool processFile(const std::string& filename, const std::string& s1, const std::string& s2);

#endif