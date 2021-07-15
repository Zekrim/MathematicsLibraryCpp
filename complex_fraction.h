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