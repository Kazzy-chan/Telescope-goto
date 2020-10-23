import 'package:telescope_goto_app/services/Comand.dart';
import 'package:telescope_goto_app/services/NumStringHelper.dart';

class TimeComand implements Comand {
  DateTime time;

  TimeComand(this.time);

  @override
  String getComandString() {
    String hours = NumStringHelper.intToXDigits(this.time.hour, 2);
    String minutes = NumStringHelper.intToXDigits(this.time.minute, 2);
    String seconds = NumStringHelper.intToXDigits(this.time.second, 2);

    return ":time=$hours:$minutes:$seconds;";
  }
}
