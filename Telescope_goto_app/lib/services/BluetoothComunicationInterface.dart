import 'dart:async';
import 'dart:convert';
import 'dart:io';
import 'dart:typed_data';

import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';

import 'Comand.dart';
import 'ComunicationInterface.dart';

class BluetoothComunicationInterface implements ComunicationInterface {
  BluetoothDevice device;
  BluetoothConnection connection;

  BluetoothComunicationInterface(this.device);

  Future<bool> connect() {
    return BluetoothConnection.toAddress(this.device.address)
        .then((connection) {
      this.connection = connection;
      return true;
    }).catchError((e) => false);
  }

  @override
  void send(String msg) {
    if (!this.connection.isConnected) {
      this.connect();
    }
    this.connection.output.add(ascii.encode(msg));
  }

  @override
  void sendComand(Comand comand) {
    this.send(comand.getComandString());
  }

  @override
  Stream<Uint8List> recive() {
    return this.connection.input.asBroadcastStream();
    // return this.socket.last.then((value) => value.toString());
  }
}
