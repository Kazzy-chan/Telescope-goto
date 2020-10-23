import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';

class BluetoothListEntry extends StatelessWidget {
  final BluetoothDevice device;
  final void Function() onPressed;
  const BluetoothListEntry(
      {Key key, @required this.device, @required this.onPressed})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return FlatButton(
      padding: EdgeInsets.all(8.0),
      onPressed: this.onPressed,
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Icon(Icons.bluetooth),
          Text(this.device == null ? "NULL" : this.device.name,
              textScaleFactor: 1.2),
          Icon(Icons.arrow_forward),
        ],
      ),
    );
  }
}
