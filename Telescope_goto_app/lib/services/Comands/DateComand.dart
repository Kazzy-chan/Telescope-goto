import 'package:telescope_goto_app/services/Comand.dart';
import 'package:telescope_goto_app/services/NumStringHelper.dart';

class DateComand implements Comand {
  DateTime date;

  DateComand(this.date);

  @override
  String getComandString() {
    String day = NumStringHelper.intToXDigits(this.date.day, 2);
    String month = NumStringHelper.intToXDigits(this.date.month, 2);
    String year = this.date.year.toString().substring(2);

    return ":date=$month/$day/$year;";
  }
}
