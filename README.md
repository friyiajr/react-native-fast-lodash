# react-native-fast-lodash

## NOTE: This is an experimental project I've been working on with JSI. It is nowhere near completed and currently on pause. I've been running into performance issues with JSI arrays that need to be resolved by the React-Native team before I plan to pick it up again.

lodash reimplemented in C++ for React Native apps

## Installation

```sh
yarn add react-native-fast-lodash
```

## Usage

```js
import { gcd } from 'react-native-fast-lodash';

// ...

const gcdVal = gcd({
  a: firstVal,
  b: secondVal,
});
```

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT
