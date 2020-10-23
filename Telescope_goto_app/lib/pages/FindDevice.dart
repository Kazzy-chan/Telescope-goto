import 'package:flare_flutter/flare_actor.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:telescope_goto_app/widgets/BluetoothList.dart';
import 'package:telescope_goto_app/widgets/TcpConnectionForm.dart';

class FindDevice extends StatelessWidget {
  const FindDevice({Key key}) : super(key: key);
  static String bluetoothNotAvailable =
      "Your Device dose not Support Bluetooth.\n For debugging purposed TCP can be used";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: [
              LimitedBox(
                maxHeight: 200,
                maxWidth: 100,
                child: FlareActor(
                  "assets/Telescope.flr",
                  animation: "Searching",
                  fit: BoxFit.contain,
                ),
              ),
              FutureBuilder(
                future: FlutterBluetoothSerial.instance.isAvailable,
                builder: (context, snapshot) {
                  if (snapshot.data) {
                    return BluetoothList();
                  } else {
                    return Center(
                      child: Column(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Text(
                            bluetoothNotAvailable,
                            textAlign: TextAlign.center,
                          ),
                          TcpConnectionForm()
                        ],
                      ),
                    );
                  }
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}
