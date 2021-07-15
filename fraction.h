#include <iostream>
#include <string>

class fraction
{
  private:
    long long numerator;
    long long denominator;

    void simplify()
    {
      
      if(denominator < 0)
      {
        numerator *= -1;
        denominator *= -1;
      }

      //TODO: Optimize
      long long counter = 2;
      while(counter <= std::abs(numerator))
      {
        if(numerator % counter + denominator % counter == 0)
        {
          numerator /= counter;
          denominator /= counter;
        }
        else
        {
          counter++;
        }
      }
    }

  public:
    /*
     * The default constructor.
     */
    fraction()
    {
      
    }

    /*
     * Takes a numerator and a denominator and then simplifies the result.
     */
    fraction(long long numerator, long long denominator)
    {
      this->numerator = numerator;
      this->denominator = denominator;
      simplify();
    }

    /*
     * Takes a fractional numerator and a fractional denominator and simplifies the result.
     */
    fraction(fraction numerator, fraction denominator)
    {
      this->numerator = numerator.get_numerator() * denominator.get_denominator();
      this->denominator = numerator.get_denominator() * denominator.get_numerator();
      simplify();
    }

    /*
     * Takes a numerator and presumes the denominator is 1.
     */
    fraction(long long whole_number)
    {
      numerator = whole_number;
      denominator = 1;
    }

    /*
     * Takes a numerator and a denominator in a single input string, separated by a backslash ('/')
     */
    fraction(std::string str)
    {
      long long backslash_position;
      for(int i = 0; i < str.length(); i++)
      {
        if(str[i] == '/')
        {
          backslash_position = i;
          break;
        }
      }

      numerator = std::stoi(str.substr(0, backslash_position));
      denominator = std::stoi(str.substr(backslash_position + 1));
      simplify();
    }

    /*
     * Returns the numerator and the denominator in string format, separated by a backslash ('/')
     */
    std::string to_string()
    {
      if(denominator != 1)
      {
        return std::to_string(numerator) + '/' + std::to_string(denominator);
      }
      else
      {
        return std::to_string(numerator);
      }
    }

    /*
     * Adds a whole number value from the fraction, returning the result.
     */
    fraction operator+(long long x)
    {
      return fraction(numerator + x * denominator, denominator);
    }

    /*
     * Subtracts a whole number value from the fraction, returning the result.
     */
    fraction operator-(long long x)
    {
      return fraction(numerator - x * denominator, denominator);
    }

    /*
     * Multiplies the fraction by a whole number, returning the simplified result.
     */
    fraction operator*(long long x)
    {
      fraction returned_value = fraction(numerator * x, denominator);
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Divides the fraction by a whole number, returning the simplified result.
     */
    fraction operator/(long long x)
    {
      fraction returned_value = fraction(numerator, denominator * x);
      returned_value.simplify();
      return returned_value; 
    }

    /*
     * Returns the remainder of a fraction and a whole number.
     */
    fraction operator%(long long x)
    {
      fraction returned_value = fraction(numerator % denominator, denominator);
      return returned_value;
    }

    /*
     * Adds a whole number to the current fraction.
     */
    void operator+=(long long x)
    {
      numerator += x * denominator;
    }

    /*
     * Subtracts a whole number from the current fraction.
     */
    void operator-=(long long x)
    {
      numerator -= x * denominator;
    }

    /*
     * Multiplies a whole number by the current fraction, and then simplifies the current fraction.
     */
    void operator*=(long long x)
    {
      numerator *= x * denominator;
      simplify();
    }

    /*
     * Divides a whole number by the current fraction, and then simplifies the current fraction.
     */
    void operator/=(long long x)
    {
      denominator *= x * denominator;
      simplify();
    }

    /*
     * Sets the current fraction to the remainder of itself and a whole number.
     */
    void operator%=(long long x)
    {
      numerator %= denominator;
    }
    
    /*
     * Adds a fraction to another, returning the simplified result.
     */
    fraction operator+(fraction f)
    {
      fraction returned_value = fraction(numerator * f.get_denominator() + f.get_numerator() * denominator, denominator * f.get_denominator());
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Subtracts a fraction from another, returning the simplified result.
     */
    fraction operator-(fraction f)
    {
      fraction returned_value = fraction(numerator * f.get_denominator() - f.get_numerator() * denominator, denominator * f.get_denominator());
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Multiplies a fraction from another, returning the simplified result.
     */
    fraction operator*(fraction f)
    {
      fraction returned_value = fraction(numerator * f.get_numerator(), denominator * f.get_denominator());
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Divides a fraction from another, returning the simplified result.
     */
    fraction operator/(fraction f)
    {
      fraction returned_value = fraction(numerator * f.get_denominator(), denominator * f.get_numerator());
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Gets the remainder from two fractions, returning the simplified result.
     */
    fraction operator%(fraction f)
    {
      fraction returned_value = fraction(numerator * f.get_denominator() % f.get_numerator() * denominator, denominator * f.get_denominator());
      returned_value.simplify();
      return returned_value;
    }

    /*
     * Sets a fraction to the simplified sum of itself and another fraction.
     */
    void operator+=(fraction f)
    {
      long long temp_numerator = numerator * f.get_denominator() + denominator * f.get_numerator();
      long long temp_denominator = denominator * f.get_denominator();
      numerator = temp_numerator;
      denominator = temp_denominator;
      simplify();
    }

    /*
     * Sets a fraction to the simplified difference of itself and another fraction.
     */
    void operator-=(fraction f)
    {
      long long temp_numerator = numerator * f.get_denominator() - denominator * f.get_numerator();
      long long temp_denominator = denominator * f.get_denominator();
      numerator = temp_numerator;
      denominator = temp_denominator;
      simplify(); 
    }

    /*
     * Sets a fraction to the simplified product of itself and another fraction.
     */
    void operator*=(fraction f)
    {
      numerator *= f.get_numerator();
      denominator *= f.get_denominator();
      simplify();
    }

    /*
     * Sets a fraction to the simplified quotient of itself and another fraction.
     */
    void operator/=(fraction f)
    {
      numerator *= f.get_denominator();
      denominator *= f.get_numerator();
    }

    /*
     * Sets a fraction to the simplified remainder of itself and another fraction.
     */
    void operator%=(fraction f)
    {
      long long temp_numerator = numerator * f.get_denominator() % f.get_numerator() * denominator;
      long long temp_denominator = denominator * f.get_denominator();

      numerator = temp_numerator;
      denominator = temp_denominator;
      simplify();
    }

    /*
     * Determines if a fraction is less than a given whole number.
     */
    bool operator<(long long x)
    {
      return numerator / denominator < x; 
    }

    /*
     * Determines if a fraction is less than or equal to a given whole number.
     */
    bool operator<=(long long x)
    {
      return numerator / denominator <= x;
    }

    /*
     * Determines if a fraction is equal to a given whole number.
     */
    bool operator==(long long x)
    {
      return numerator == x && denominator == 2;
    }

    /*
     * Determines if a fraction is greater than or equal to a given whole number.
     */
    bool operator>=(long long x)
    {
      return numerator / denominator >= x;
    }

    /*
     * Determines if a fraction is greater than a given whole number.
     */
    bool operator>(long long x)
    {
      return numerator / denominator > x || (numerator / denominator == x && numerator % denominator > 0);
    }

    /*
     * Determines if a fraction is less than another fraction.
     */
    bool operator<(fraction f)
    {
      return numerator * f.get_denominator() < denominator * f.get_numerator();
    }

    /*
     * Determines if a fraction is less than or equal to another fraction.
     */
    bool operator<=(fraction f)
    {
      return numerator * f.get_denominator() <= denominator * f.get_numerator();
    }

    /*
     * Determines if a fraction is equal to another fraction.
     */
    bool operator==(fraction f)
    {
      return numerator == f.get_numerator() && denominator == f.get_denominator();
    }

    /*
     * Determines if a fraction is greater than or equal to another fraction.
     */
    bool operator>=(fraction f)
    {
      return numerator * f.get_denominator() >= denominator * f.get_numerator();
    }

    /*
     * Determines if a fraction is greather than another fraction.
     */
    bool operator>(fraction f)
    {
      return numerator * f.get_denominator() > denominator * f.get_numerator();
    }

    /*
     * Returns the inverse of a fraction.
     */
    fraction get_inverse()
    {
      return fraction(denominator, numerator);
    }

    /*
     * Inverts a fraction.
     */
    void invert()
    {
      long long tempNumerator = numerator;
      numerator = denominator;
      denominator = tempNumerator;
    }

    /*
     * Returns the numerator of the fraction.
     */
    long long get_numerator()
    {
      return numerator;
    }
    
    /*
     * Returns the denominator of the fraction.
     */
    long long get_denominator()
    {
      return denominator;
    }
};