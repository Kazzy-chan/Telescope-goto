import 'dart:async';

import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:telescope_goto_app/pages/ConnectionManagmentTopPage.dart';
import 'package:telescope_goto_app/services/BluetoothComunicationInterface.dart';

import 'BluetoothListEntry.dart';

class BluetoothList extends StatefulWidget {
  const BluetoothList({Key key}) : super(key: key);

  @override
  _BluetoothListState createState() => _BluetoothListState();
}

class _BluetoothListState extends State<BluetoothList> {
  StreamSubscription sub;
  List<BluetoothDevice> devices = [];
  bool searching = false;

  @override
  void initState() {
    super.initState();

    this.startScaning();
  }

  void startScaning() {
    this.setState(() {
      searching = true;
    });
    sub = FlutterBluetoothSerial.instance.startDiscovery().listen((event) {
      this.setState(() {
        devices.add(event.device);
      });
      print(event.device.name);
    });

    sub.onDone(() {
      print("DONE");
      this.setState(() {
        searching = false;
      });
      this.startScaning();
    });
  }

  @override
  void dispose() {
    this.sub.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return RefreshIndicator(
      onRefresh: () {
        this.startScaning();
      },
      child: StreamBuilder(
        stream: FlutterBluetoothSerial.instance.onStateChanged(),
        builder: (context, snapshot) {
          return FutureBuilder(
            future: FlutterBluetoothSerial.instance.state,
            builder: (context, snapshot) {
              if (snapshot.data == BluetoothState.STATE_ON) {
                return Column(
                    children: devices
                        .map<Widget>((device) => BluetoothListEntry(
                              device: device,
                              onPressed: () async {
                                BluetoothComunicationInterface interface =
                                    BluetoothComunicationInterface(device);
                                if (await interface.connect()) {
                                  Navigator.push(
                                      context,
                                      MaterialPageRoute(
                                        builder: (context) =>
                                            ConnectionManagmentTopPage(
                                          comunicationInterface: interface,
                                        ),
                                      ));
                                }
                              },
                            ))
                        .toList());
              } else {
                return Text("OFF");
              }
            },
          );
        },
      ),
    );
  }
}
