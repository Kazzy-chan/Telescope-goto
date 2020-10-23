import 'dart:async';
import 'dart:convert';
import 'dart:io';
import 'dart:typed_data';

import 'Comand.dart';
import 'ComunicationInterface.dart';

class TcpComunicationInterface implements ComunicationInterface {
  String ip;
  int port;
  Socket socket;

  TcpComunicationInterface(this.ip, this.port);

  Future<bool> connect() {
    return Socket.connect(this.ip, this.port, timeout: Duration(seconds: 2))
        .then((socket) {
      this.socket = socket;
      return true;
    }).catchError((error) => false);
  }

  @override
  void send(String msg) {
    this.socket.add(ascii.encode(msg));
  }

  @override
  void sendComand(Comand comand) {
    this.socket.add(ascii.encode(comand.getComandString()));
  }

  @override
  Stream<Uint8List> recive() {
    return this.socket.asBroadcastStream();
    // return this.socket.last.then((value) => value.toString());
  }
}
