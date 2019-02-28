#ifndef MY_VECTOR2
#define My_Vector2

#include <SFML/Graphics.hpp>

const float PI = 3.14159265359f;
float vectorLength(const sf::Vector2f t_vector);
float vectorLengthSquared(const sf::Vector2f t_vector);
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector);
float vectorCrossProduct(sf::Vector2f t_VectorA, sf::Vector2f t_VectorB);
float vectorDotProduct(sf::Vector2f t_VectorA, sf::Vector2f t_VectorB);
float angleBetweenVectors(sf::Vector2f t_VectorA, sf::Vector2f t_VectorB);
sf::Vector2f vectorRotateBy(sf::Vector2f t_Vector, float t_angleRadians);
sf::Vector2f vectorProjection(sf::Vector2f t_Vector, sf::Vector2f t_onto);
sf::Vector2f vectorRejection(sf::Vector2f t_Vector, sf::Vector2f t_onto);
float vectorScalerProjection(sf::Vector2f t_Vector, sf::Vector2f t_onto);

#endif // MY_VECTOR2