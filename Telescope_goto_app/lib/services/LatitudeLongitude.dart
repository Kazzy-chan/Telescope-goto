import 'package:telescope_goto_app/services/GPSCoord.dart';

class LatitudeLongitude {
  double degree;
  LatitudeLongitude(this.degree);

  GPSCoord toGPSCoord() {
    String degreeString = this.degree.toString();

    int gpsDegree = num.parse(degreeString.split(".")[0]);
    String rawMin = (num.parse("0." + degreeString.split(".")[1])).toString();
    rawMin = (num.parse(rawMin) * 60).toString();
    int min = num.parse(rawMin.split(".")[0]);
    String rawSeconds = (num.parse("0." + rawMin.split(".")[1])).toString();
    rawSeconds = (num.parse(rawSeconds) * 60).toString();
    double seconds = num.parse(rawSeconds);

    return GPSCoord(degree: gpsDegree, minutes: min, seconds: seconds);
  }
}
