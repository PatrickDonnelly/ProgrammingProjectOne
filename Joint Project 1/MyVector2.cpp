#include "MyVector2.h"

/// <summary>
/// Gets length between two vectors
/// </summary>
/// <param name="t_vector"></param>
/// <returns></returns>
float vectorLength(const sf::Vector2f t_vector)
{
	float sumOfSquares = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y);
	const float length = sqrt(sumOfSquares);
	return length;
}

/// <summary>
/// squares the length between two vectors
/// </summary>
/// <param name="t_vector"></param>
/// <returns></returns>
float vectorLengthSquared(const sf::Vector2f t_vector)
{
	const float sumOfSquares = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y);
	return sumOfSquares;
}

/// <summary>
/// Cross product of two vectors
/// </summary>
/// <param name="t_vectorA"></param>
/// <param name="t_vectorB"></param>
/// <returns></returns>
float vectorCrossProduct(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	const float result = t_vectorA.x * t_vectorB.y - t_vectorA.y * t_vectorB.x;
	return result;
}

/// <summary>
/// dot product of two vectors
/// </summary>
/// <param name="t_vectorA"></param>
/// <param name="t_vectorB"></param>
/// <returns></returns>
float vectorDotProduct(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	const float result = (t_vectorA.x * t_vectorB.x) + (t_vectorA.y * t_vectorB.y);
	return result;
}

/// <summary>
/// angle between two vectors
/// </summary>
/// <param name="t_vectorA"></param>
/// <param name="t_vectorB"></param>
/// <returns></returns>
float angleBetweenVectors(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	float cosine = vectorDotProduct(vectorUnitVector(t_vectorA), vectorUnitVector(t_vectorB));

	if (cosine > 1.0f)
	{
		cosine = 1.0f;
	}
	if (cosine < -1.0f)
	{
		cosine = -1.0f;
	}
	const float angleInRadians = std::acos(cosine);
	const float angleInDegrees = angleInRadians * 180.0f / PI;
	return angleInDegrees;
}

/// <summary>
/// rotate a vector by an angle
/// </summary>
/// <param name="t_vector"></param>
/// <param name="t_angleInRadians"></param>
/// <returns></returns>
sf::Vector2f vectorRotateBy(const sf::Vector2f t_vector, const float t_angleInRadians)
{
	const float cos = std::cos(t_angleInRadians);
	const float sin = std::sin(t_angleInRadians);
	const float xComponent = (t_vector.x *cos) - (t_vector.y*sin);
	const float yComponent = (t_vector.x *sin) + (t_vector.y *cos);
	const sf::Vector2f result{ xComponent, yComponent };
	return result;
}


/// <summary>
/// projection of one vector onto another
/// </summary>
/// <param name="t_vector"></param>
/// <param name="t_onto"></param>
/// <returns></returns>
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	float scale = vectorDotProduct(t_vector, t_onto) / vectorLengthSquared(t_onto);
	const sf::Vector2f result = t_onto * scale;
	return result;
}


/// <summary>
/// rejecvtion of one vector onto another
/// </summary>
/// <param name="t_vector"></param>
/// <param name="t_onto"></param>
/// <returns></returns>
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	const sf::Vector2f result = t_vector - vectorProjection(t_vector, t_onto);
	return result;
}


/// <summary>
/// sclaer projection of one vector onto another
/// </summary>
/// <param name="t_vector"></param>
/// <param name="t_onto"></param>
/// <returns></returns>
float vectorScalerProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	float result = vectorDotProduct(t_vector, t_onto) / vectorLength(t_onto);
	return result;
}


/// <summary>
/// unit vector
/// </summary>
/// <param name="t_vector"></param>
/// <returns></returns>
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	sf::Vector2f result{ 0.0f,0.0f };
	const float length = vectorLength(t_vector);
	if (length != 0.0f)
	{
		result = sf::Vector2f{ t_vector.x / length, t_vector.y / length };
	}
	return result;
}
