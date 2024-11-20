/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:31:51 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 17:02:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

// MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);

		const std::string& getMaterias(int i) const;

	private:
		AMateria* _templates[4];

};

#endif