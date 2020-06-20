#include <cmath>
#include <iostream>

double sqr(double x) {
  return x * x;
}

int main() {
  double S_n = 100.0; // kW
  double DeltaP_xx = 1.05;  // kW
  double DeltaP_kz = 5.5;  // kW
  double WP_f = 180.0; // kWh
  double WQ_f = 120.0; // kWh

  double T_p = 720.0; // h
  double T_r = 720.0; // h
 
  std::cout << "[IN] S_n       = " << S_n << " kW" << std::endl;
  std::cout << "[IN] DeltaP_xx = " << DeltaP_xx << " kW" << std::endl;
  std::cout << "[IN] DeltaP_kz = " << DeltaP_kz << " kW" << std::endl;
  std::cout << "[IN] WP_f      = " << WP_f << " kWh" << std::endl;
  std::cout << "[IN] WQ_f      = " << WQ_f << " kWh" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "[IN] T_p = " << T_p << " h" << std::endl;
  std::cout << "[IN] T_r = " << T_r << " h" << std::endl;

  std::cout << std::endl;

  double P_f = WP_f / T_p;
  std::cout << "P_f = " << P_f << " kW" << std::endl;

  double Q_f = WQ_f / T_p;
  std::cout << "Q_f = " << Q_f << " kW" << std::endl;

  double S_f = sqrt(sqr(P_f) + sqr(Q_f));
  std::cout << "S_f = " << S_f <<  " kW" << std::endl;

  double K_z = S_f / S_n;
  std::cout << "K_z = " << K_z << std::endl;

  double K_z2 = sqr(K_z);
  std::cout << "K_z2 = " << K_z2 << std::endl;

  double DeltaWP_xx = DeltaP_xx * T_p;
  std::cout << "DeltaWP_xx = " << DeltaWP_xx << " kWh" << std::endl;

  double DeltaWP_kz = K_z2 * DeltaP_kz * T_r;
  std::cout << "DeltaWP_kz = " << DeltaWP_kz << " kWh" << std::endl;

  double DeltaWP = DeltaWP_xx + DeltaWP_kz;
  std::cout << "DeltaWP    = " << DeltaWP << " kWh" << std::endl;

  return 0;
}
