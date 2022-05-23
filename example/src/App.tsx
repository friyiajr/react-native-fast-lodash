import React, { FC, useState } from 'react';

import _ from 'react-native-fast-lodash';

import {
  View,
  Text,
  StyleSheet,
  TextInput,
  Button,
  TouchableWithoutFeedback,
  Keyboard,
  Alert,
} from 'react-native';

const sampleVals = Array.from(Array(10000000).keys());

const App = () => {
  const [firstVal, setFirstVal] = useState(1);
  const [secondVal, setSecondVal] = useState(1);

  const onChangeFirstValue = (text) => {
    setFirstVal(Number(text));
  };

  const onChangeSecondValue = (text) => {
    setSecondVal(Number(text));
  };

  const max = (allNums: number[]) => {
    let max = -9999;

    for (let i = 0; i < allNums.length; i++) {
      if (allNums[i] > max) {
        max = allNums[i];
      }
    }

    return max;
  };

  const computeResult = () => {
    // const result = _.max(sampleVals);
    const result = max(sampleVals);
    Alert.alert(`Your answer: ${result}`);
  };

  return (
    <TouchableWithoutFeedback onPress={Keyboard.dismiss}>
      <View style={styles.container}>
        <View>
          <TextInput
            value={firstVal + ''}
            onChangeText={onChangeFirstValue}
            keyboardType="numeric"
            style={styles.textInput}
          />
          <TextInput
            value={secondVal + ''}
            onChangeText={onChangeSecondValue}
            keyboardType="numeric"
            style={styles.textInput}
          />
        </View>
        <View>
          <Button title="Compute Result" onPress={computeResult} />
        </View>
      </View>
    </TouchableWithoutFeedback>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'space-around',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  textInput: {
    backgroundColor: 'lightgrey',
    marginVertical: 10,
    width: 75,
    paddingVertical: 10,
    justifyContent: 'center',
    alignContent: 'center',
    textAlign: 'center',
  },
});

export default App;
