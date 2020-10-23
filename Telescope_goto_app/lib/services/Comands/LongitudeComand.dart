import 'package:telescope_goto_app/services/Comand.dart';
import 'package:telescope_goto_app/services/GPSCoord.dart';
import 'package:telescope_goto_app/services/NumStringHelper.dart';

class LongitudeComand implements Comand {
  GPSCoord gpsCoord;

  LongitudeComand(this.gpsCoord);

  @override
  String getComandString() {
    String sign = gpsCoord.degree > 0 ? "+" : "";
    String degree = NumStringHelper.intToXDigits(gpsCoord.degree, 3);
    String minutes = NumStringHelper.intToXDigits(gpsCoord.minutes, 2);
    String seconds = NumStringHelper.intToXDigits(gpsCoord.seconds.round(), 2);
    return ":longitude=$sign$degree*$minutes:$seconds;";
  }
}
