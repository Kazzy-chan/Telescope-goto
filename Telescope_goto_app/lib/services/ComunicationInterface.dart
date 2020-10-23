import 'dart:typed_data';

import 'Comand.dart';

abstract class ComunicationInterface {
  void send(String msg);
  void sendComand(Comand comand);
  Stream<Uint8List> recive();
}
