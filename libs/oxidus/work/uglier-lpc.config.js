export default {
  // Files can be provided via CLI args; this list is optional.
  files: ["**/*.c"],
  ignore: ["**/fluffos/**"],
  rules: {
    "brace-style": {
      style: "kr" // "kr" | "allman"
    },
    "indent-style": {
      size: 2, // spaces per indent level
      style: "space"
    },
    "trim-trailing-whitespace": true,
    "line-length": {
      length: 80,
      ignoreComments: true,
    }
  }
}
