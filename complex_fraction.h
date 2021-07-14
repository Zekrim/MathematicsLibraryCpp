 #include "fraction.h"

class complex_fraction
{
  private:
    fraction real_part;
    fraction imaginary_part;
  public:
    complex_fraction(fraction real, fraction imaginary)
    {
      real_part = fraction(real.get_numerator(), real.get_denominator());
      imaginary_part = fraction(imaginary.get_numerator(), imaginary.get_denominator());
    }

    complex_fraction(std::string real, std::string imaginary)
    {
      real_part = fraction(real);
      imaginary_part = fraction(imaginary);
    }
    
    fraction get_real_part()
    {
      return real_part;
    }

    fraction get_imaginary_part()
    {
      return imaginary_part;
    }

    std::string to_string()
    {
      if(imaginary_part.get_numerator() < 0)
      {
        return real_part.to_string() + imaginary_part.to_string() + "i";
      }
      return real_part.to_string() + "+" + imaginary_part.to_string() + "i";
    }

    complex_fraction operator+(complex_fraction other_comp)
    {
      fraction new_real_part = real_part + other_comp.get_real_part();
      fraction new_imaginary_part = imaginary_part + other_comp.get_imaginary_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    complex_fraction operator-(complex_fraction other_comp)
    {
      fraction new_real_part = real_part - other_comp.get_real_part();
      fraction new_imaginary_part = imaginary_part + other_comp.get_imaginary_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    complex_fraction operator*(complex_fraction other_comp)
    {
      fraction new_real_part = real_part * other_comp.get_real_part() - imaginary_part * other_comp.get_imaginary_part();
      fraction new_imaginary_part = real_part * other_comp.get_imaginary_part() + imaginary_part * other_comp.get_real_part();
      return complex_fraction(new_real_part, new_imaginary_part);
    }

    complex_fraction operator/(complex_fraction other_comp)
    {
      fraction r_num = real_part * other_comp.get_real_part() + imaginary_part * other_comp.get_imaginary_part();
      fraction c_denom = other_comp.get_real_part() * other_comp.get_real_part() + other_comp.get_imaginary_part() * other_comp.get_imaginary_part();
      fraction i_num = other_comp.get_real_part() * imaginary_part - real_part * other_comp.get_imaginary_part();
      return complex_fraction(fraction(r_num, c_denom), fraction(i_num, c_denom));
    }

    void operator+=(complex_fraction other_comp)
    {
      complex_fraction self = fraction(real_part, imaginary_part);
      self = self + other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    void operator-=(complex_fraction other_comp)
    {
      complex_fraction self = fraction(real_part, imaginary_part);
      self = self - other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    void operator*=(complex_fraction other_comp)
    {
      complex_fraction self = fraction(real_part, imaginary_part);
      self = self * other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    void operator/=(complex_fraction other_comp)
    {
      complex_fraction self = fraction(real_part, imaginary_part);
      self = self / other_comp;
      real_part = self.get_real_part();
      imaginary_part = self.get_imaginary_part();
    }

    bool operator==(complex_fraction other_comp)
    {
      return real_part == other_comp.get_real_part() && imaginary_part == other_comp.get_imaginary_part();
    }
};