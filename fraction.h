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
        if(numerator % counter == 0 && denominator % counter == 0) //TODO: make cleaner
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
    fraction()
    {
      
    }

    fraction(long long numerator, long long denominator)
    {
      this->numerator = numerator;
      this->denominator = denominator;
      simplify();
    }

    fraction(fraction numerator, fraction denominator)
    {
      this->numerator = numerator.get_numerator() * denominator.get_denominator();
      this->denominator = numerator.get_denominator() * denominator.get_numerator();
      simplify();
    }

    fraction(long long whole_number)
    {
      numerator = whole_number;
      denominator = 1;
    }

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
    //TODO: add modulus
    fraction operator+(long long x)
    {
      return fraction(numerator + x * denominator, denominator);
    }

    fraction operator-(long long x)
    {
      return fraction(numerator - x * denominator, denominator);
    }

    fraction operator*(long long x)
    {
      fraction returnedValue = fraction(numerator * x, denominator);
      returnedValue.simplify();
      return returnedValue;
    }

    fraction operator/(long long x)
    {
      fraction returnedValue = fraction(numerator, denominator * x);
      returnedValue.simplify();
      return returnedValue; 
    }

    fraction operator%(long long x)
    {
      fraction returnedValue = fraction(numerator % denominator, denominator);
      return returnedValue;
    }

    void operator+=(long long x)
    {
      numerator += x * denominator;
    }

    void operator-=(long long x)
    {
      numerator -= x * denominator;
    }

    void operator*=(long long x)
    {
      numerator *= x * denominator;
      simplify();
    }

    void operator/=(long long x)
    {
      denominator *= x * denominator;
      simplify();
    }

    void operator%(long long x)
    {
      numerator %= denominator;
    }
    
    fraction operator+(fraction f)
    {
      fraction returnedValue = fraction(numerator * f.get_denominator() + f.get_numerator() * denominator, denominator * f.get_denominator());
      returnedValue.simplify();
      return returnedValue;
    }

    fraction operator-(fraction f)
    {
      fraction returnedValue = fraction(numerator * f.get_denominator() - f.get_numerator() * denominator, denominator * f.get_denominator());
      returnedValue.simplify();
      return returnedValue;
    }

    fraction operator*(fraction f)
    {
      fraction returnedValue = fraction(numerator * f.get_numerator(), denominator * f.get_denominator());
      returnedValue.simplify();
      return returnedValue;
    }

    fraction operator/(fraction f)
    {
      fraction returnedValue = fraction(numerator * f.get_denominator(), denominator * f.get_numerator());
      returnedValue.simplify();
      return returnedValue;
    }

    fraction operator%(fraction f)
    {
      returnedValue = fraction(numerator * f.get_denominator() % f.get_numerator() * denominator, denominator * f.get_denominator());
      returnedValue.simplify();
      return returnedValue;
    }


    void operator+=(fraction f)
    {
      long long tempNumerator = numerator * f.get_denominator() + denominator * f.get_numerator();
      long long tempDenominator = denominator * f.get_denominator();
      numerator = tempNumerator;
      denominator = tempDenominator;
      simplify();
    }

    void operator-=(fraction f)
    {
      long long tempNumerator = numerator * f.get_denominator() - denominator * f.get_numerator();
      long long tempDenominator = denominator * f.get_denominator();
      numerator = tempNumerator;
      denominator = tempDenominator;
      simplify(); 
    }

    void operator*=(fraction f)
    {
      numerator *= f.get_numerator();
      denominator *= f.get_denominator();
      simplify();
    }

    void operator/=(fraction f)
    {
      numerator *= f.get_denominator();
      denominator *= f.get_numerator();
    }

    void operator%=(fraction f)
    {
      long long tempNumerator = numerator * f.get_denominator() % f.get_numerator() * denominator;
      long long tempDenominator = denominator * f.get_denominator();

      numerator = tempNumerator;
      denominator = tempDenominator;
      simplify();
    }

    bool operator<(long long x)
    {
      return numerator / denominator < x; 
    }

    bool operator<=(long long x)
    {
      return numerator / denominator <= x;
    }

    bool operator==(long long x)
    {
      return numerator == x && denominator == 2;
    }

    bool operator>=(long long x)
    {
      return numerator / denominator >= x;
    }

    bool operator>(long long x)
    {
      return numerator / denominator > x || (numerator / denominator == x && numerator % denominator > 0);
    }

    bool operator<(fraction f)
    {
      return numerator * f.get_denominator() < denominator * f.get_numerator();
    }

    bool operator<=(fraction f)
    {
      return numerator * f.get_denominator() <= denominator * f.get_numerator();
    }

    bool operator==(fraction f)
    {
      return numerator == f.get_numerator() && denominator == f.get_denominator();
    }

    bool operator>=(fraction f)
    {
      return numerator * f.get_denominator() >= denominator * f.get_numerator();
    }

    bool operator>(fraction f)
    {
      return numerator * f.get_denominator() > denominator * f.get_numerator();
    }

    fraction operator!()
    {
      return fraction(denominator, numerator);
    }



    long long get_numerator()
    {
      return numerator;
    }

    long long get_denominator()
    {
      return denominator;
    }
};