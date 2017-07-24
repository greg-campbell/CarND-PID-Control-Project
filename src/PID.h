#ifndef PID_H
#define PID_H

#include <limits>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  double dp[3] = {1.0, 1.0, 1.0};
  double best_err = std::numeric_limits<double>::max();
  double err = 0;
  int n = 0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double TwiddleError(double p[]) const;
  void Twiddle();
};

#endif /* PID_H */
