class NumStringHelper {
  static String doubletoXDigits(double value, int maxNums) {
    String stringValue = value.toString();
    if (stringValue.length < maxNums) {
      for (int i = stringValue.length; i < maxNums; i++) {
        stringValue = "0" + stringValue;
      }
    } else if (stringValue.length > maxNums) {
      stringValue = stringValue.substring(0, maxNums);
    }

    return stringValue;
  }

  static String intToXDigits(int value, int maxNums) {
    value.isNegative ? maxNums++ : null;
    String stringValue = value.toString();
    if (stringValue.length < maxNums) {
      for (int i = stringValue.length; i < maxNums; i++) {
        stringValue = "0" + stringValue;
      }
    } else if (stringValue.length > maxNums) {
      throw "int longer than maxNums";
    }

    return stringValue;
  }
}
