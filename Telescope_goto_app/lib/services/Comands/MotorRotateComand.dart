import 'package:flutter/cupertino.dart';
import 'package:telescope_goto_app/services/Comand.dart';

class MotorRotateComand implements Comand {
  int motor;
  bool start;
  bool clockwise;

  MotorRotateComand({
    @required this.motor,
    @required this.start,
    this.clockwise,
  });

  @override
  String getComandString() {
    if (clockwise != null) {
      return ":move=$motor:${start ? "on" : "off"}:${clockwise ? "clockwise" : "counterclockwise"};";
    } else {
      return ":move=$motor:${start ? "on" : "off"};";
    }
  }
}
