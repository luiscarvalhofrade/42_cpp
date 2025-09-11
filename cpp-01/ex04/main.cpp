/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:32:19 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/07 13:48:57 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Sed.hpp"

int main(int arc, char** argv) {
    if (arc != 4)
    {
        std::cout << "Parameter(s) missing !!!" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    processFile(filename, s1, s2);
    return (0);
}
