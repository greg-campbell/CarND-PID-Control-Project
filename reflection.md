# CarND-Controls-PID
## Effect of Components

* Increasing the proportional gain controls the oscillations. If the proportional gain is set too high, the car oscillates too much around the center of the track and may eventually become unstable and drive off the track. If the proportional gain is set too low, the car can't adequately account for turns in time and will drive off the track. I used an initial value of 0.1 for the proportional gain.

* The integral gain is normally used to account for steady-state error and to offset measurement bias, which does not seem to be applicable in this simulator. Therefore, I used a value of 0 for the integral gain and did not allow the gradient descent parameter optimization to adjust it.

* The derivative gain controls how quickly the system can settle. Too large a value can cause the system to fail to correct in time when entering turns, but will decrease the amount of overshoot and allow the system to settle more quickly. I used an initial value of 0.6 for the derivative gain.

## Parameter Optimization

The initial parameters were manually tuned by adjusting them and observing the impact on the car's stability. Twiddle is used to adjust the parameters based on the average error accumulated over several measurements.

The average crosstrack error is calculated every `twiddle_freq` measurements (in this case, 6). If the squared average crosstrack error exceeds 1.0, Twiddle is run to re-optimize the proportional and derivative gains. At this time, the car's throttle is reduced if the car's speed exceeds 40, in order to allow the vehicle to recover using the adjusted parameters.


