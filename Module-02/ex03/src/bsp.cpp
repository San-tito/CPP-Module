/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 10:53:09 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed ax(a.getX());
	Fixed ay(a.getY());
	Fixed bx(b.getX());
	Fixed by(b.getY());
	Fixed cx(c.getX());
	Fixed cy(c.getY());
	Fixed computed(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
	return ((computed < Fixed(0)) ? Fixed(-1) * computed : computed);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero(0);
	Fixed abc(area(a, b, c));
	Fixed pbc(area(point, b, c));
	Fixed pac(area(point, a, c));
	Fixed pab(area(point, a, b));
	return (abc == (pbc + pac + pab)) && (pbc > zero) && (pac > zero)
		&& (pab > zero);
}

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);
	Point inside(2.5f, 1.0f);
	Point onEdge(2.5f, 0.0f);
	Point outside(6.0f, 6.0f);
	std::cout << "Point inside the triangle: ";
	std::cout << (bsp(a, b, c, inside) ? "True" : "False") << '\n';
	std::cout << "Point on the edge of the triangle: ";
	std::cout << (bsp(a, b, c, onEdge) ? "True" : "False") << '\n';
	std::cout << "Point outside the triangle: ";
	std::cout << (bsp(a, b, c, outside) ? "True" : "False") << '\n';
}
