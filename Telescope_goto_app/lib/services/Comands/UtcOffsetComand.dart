import 'package:telescope_goto_app/services/Comand.dart';
import 'package:telescope_goto_app/services/NumStringHelper.dart';

class UtcOffsetComand implements Comand {
  DateTime date;

  UtcOffsetComand(this.date);

  @override
  String getComandString() {
    String sign = this.date.timeZoneOffset.isNegative ? "-" : "+";
    String hour = NumStringHelper.intToXDigits(date.timeZoneOffset.inHours, 2);

    return ":utcOffset=$sign$hour.0;";
  }
}
