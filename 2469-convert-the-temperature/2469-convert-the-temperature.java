class Solution {
    public double[] convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.0;

        return new double[]{kelvin, fahrenheit};
    }
}