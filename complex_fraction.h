 #include "fraction.h"

class complex_fraction
{
  private:
    fraction real_part;
    fraction imaginary_part;
  public:
    /*
     * Creates a complex number from two fractional components : one real, one imaginary.
     */
    complex_fraction(fraction real, fraction imaginary)
    {
      real_part = fraction(real.get_numerator(), real.get_denominator());
      imaginary_part = fraction(imaginary.get_numerator(), imaginary.get_denominator());
    }

    /*
     * Creates a complex number from two strings each representing a fraction (each having a numerator and a denominator, separated by a backslash ('\'))
     */
    complex_fraction(std::string real, std::string imaginary)
    {
      real_part = fraction(real);
      imaginary_part = fraction(imaginary);
    }

    /*
     * Returns the real component of the complex number.
     */    
    fraction get_real_part()
    {
      return real_part;
    }

    /*
     * Returns the imaginary component of the complex number.
     */
    fraction get_imaginary_part()
    {
      return imaginary_part;
    }

    /*
     * Returns the string representation of the complex number : the real component, followed by a plus sign, followed by the imaginary component, followed by the character 'i'.
     */
    std::string to_string()
    {
      if(imaginary_part.get_numerator() < 0)
      {
        return real_part.to_string() + imaginary_part.to_string() + "i";
      }
      return real_part.to_string() + "+" + imaginary_part.to_string() + "i";
    }
    
    /*
     * Returns the sum of the complex number and a real whole number.
     */
    complex_fraction operator+(long long x)
    {
      return complex_fraction(real_part + x, imaginary_part);
    }

    /*
     * Returns the difference of the complex number and a real whole number.
     */
    complex_fraction operator-(long long x)
    {
      return complex_fraction(real_part - x, imaginary_part);
    }

    /*
     * Returns the product of the complex number and a real whole number.
     */
    complex_fraction operator*(long long x)
    {
      return complex_fraction(real_part * x, imaginary_part * x);
    }

    /*
     * Returns the quotient of the complex number and a real whole number.
     */
    complex_fraction operator/(long long x)
    {
      return complex_fraction(real_part / x, imaginary_part / x);
    }

    /*
     * Takes the current complex number and adds a real whole number to it.
     */
    void operator+=(long long x)
    {
      real_part += x;
    }

    /*
     * Takes the current complex number and divides a real whole number from it.
     */
    void operator-=(long long x)
    {
      real_part -= x;
    }

    /*
     * Takes the current complex number and multiplies the real and imaginary elements by a real whole number.
     */
    void operator*=(long long x)
    {
      real_part *= x;
      imaginary_part *= x;
    }

    /*
     * Takes the current complex number and divides the real and imaginary elements by a real whole number.
     */
    void operator/=(long long x)
    {
      real_part /= x;
      imaginary_part /= x;
    }

    /*
     * Returns the sum of the complex number and a real fraction.
     */
    complex_fraction operator+(fraction x)
    {
      return complex_fraction(real_part + x, imaginary_part);
    }

    /*
     * Returns the difference of the complex number and a real fraction.
     */
    complex_fraction operator-(fraction x)
    {
      return complex_fraction(real_part - x, imaginary_part);
    }

    /*
     * Returns the product of a complex number and a real whole number.
     */
    complex_fraction operator*(fraction x)
    {
      return complex_fraction(real_part * x, imaginary_part * x);
    }

    /*
     * Returns the quotient of a complex number and a real whole number.
     */
    complex_fraction operator/(fraction x)
    {
      return complex_fraction(real_part / x, imaginary_part / x);
    }

    /*
     * Takes the current number and adds a real fraction to it.
     */
    void operator+=(fraction x)
    {
      real_part += x;
    }

    /*
     * Takes the current number and subtracts a real fraction from it.
     */
    void operator-=(fraction x)
    {
      real_part -= x;
    }

    /*
     * Takes the current number and multiplies it by a real fraction.
     */
    void operator*=(fraction x)
    {
      real_part *= x;
      imaginary_part *= x;
    }

    /*
     * Takes the current number and divides it by a real fraction.
     */
    void operator/=(fraction x)
    {
      real_part /= x;
      imaginary_part /= x;
    }

    /*
     * Returns the sum of the current complex number and another complex number.
     */
    complex_fraction operator+(complex_fraction other_comp)
    {
      fraction new_real_part = real_part + other_comp.get_real_part();
      fraction new_imaginary_part = imaginary_part + other_comp.get_imaginary_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    /*
     * Returns the difference of the current complex number and another complex number.
     */
    complex_fraction operator-(complex_fraction other_comp)
    {
      fraction new_real_part = real_part - other_comp.get_real_part();
      fraction new_imaginary_part = imaginary_part + other_comp.get_imaginary_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    /*
     * Returns the product of the current complex number and another complex number.
     */
    complex_fraction operator*(complex_fraction other_comp)
    {
      fraction new_real_part = real_part * other_comp.get_real_part() - imaginary_part * other_comp.get_imaginary_part();
      fraction new_imaginary_part = real_part * other_comp.get_imaginary_part() + imaginary_part * other_comp.get_real_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    /*
     * Returns the quotient of the current complex number and another complex number.
     */
    complex_fraction operator/(complex_fraction other_comp)
    {
      fraction r_num = real_part * other_comp.get_real_part() + imaginary_part * other_comp.get_imaginary_part();
      fraction c_denom = other_comp.get_real_part() * other_comp.get_real_part() + other_comp.get_imaginary_part() * other_comp.get_imaginary_part();
      fraction i_num = other_comp.get_real_part() * imaginary_part - real_part * other_comp.get_imaginary_part();
      return complex_fraction(fraction(r_num, c_denom), fraction(i_num, c_denom));
    }

    /*
     * Sets the current complex number to the sum of itself and another complex number.
     */
    void operator+=(complex_fraction other_comp)
    {
      complex_fraction self = complex_fraction(real_part, imaginary_part);
      self = self + other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    /*
     * Sets the current complex number to the difference of itself and another complex number.
     */
    void operator-=(complex_fraction other_comp)
    {
      complex_fraction self = complex_fraction(real_part, imaginary_part);
      self = self - other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    /*
     * Sets the current complex number to the product of itself and another complex number.
     */
    void operator*=(complex_fraction other_comp)
    {
      complex_fraction self = complex_fraction(real_part, imaginary_part);
      self = self * other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    /*
     * Sets the current complex number to the quotient of itself and another complex number.
     */
    void operator/=(complex_fraction other_comp)
    {
      complex_fraction self = complex_fraction(real_part, imaginary_part);
      self = self / other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    /*
     * Determines if the current complex number and another complex number are equal.
     */
    bool operator==(complex_fraction other_comp)
    {
      return real_part == other_comp.get_real_part() && imaginary_part == other_comp.get_imaginary_part();
    }
};