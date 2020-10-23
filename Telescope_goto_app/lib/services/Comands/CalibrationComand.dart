import 'package:telescope_goto_app/services/Comand.dart';

class CalibrationRaComand implements Comand {
  String ra;

  CalibrationRaComand(this.ra);

  @override
  String getComandString() {
    return ":calibrationRa=$ra;";
  }
}

class CalibrationDecComand implements Comand {
  String dec;

  CalibrationDecComand(this.dec);

  @override
  String getComandString() {
    return ":calibrationDec=$dec;";
  }
}
