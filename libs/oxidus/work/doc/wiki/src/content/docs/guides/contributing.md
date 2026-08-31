---
title: Contributing
description: How to contribute changes to the Oxidus mudlib.
sidebar:
  order: 3
---

Oxidus is actively maintained on [GitHub](https://github.com/gesslar/oxidus-mudlib) and contributions are welcome. This page covers the branching model and the workflow for getting a change merged.

## Branching Model

The `main` branch is the stable branch and is protected -- only specific users and automated tools push to it directly. All work happens on feature branches cut from `main`, and changes land back on `main` through reviewed pull requests.

## How to Contribute

1. **Create a branch** off the latest `main`:

   ```sh
   git checkout main
   git pull origin main
   git checkout -b your-feature-branch
   ```

2. **Make your changes.** Match the surrounding code -- consistent 2-space indentation, brace-on-same-line, `snake_case` naming, and LPCDoc comment headers on functions. Keep commits focused.

3. **Open a pull request** against `main`. Describe what changed and why.

4. **Review and merge.** Once the pull request is reviewed and approved, it is merged into `main`.

## Before You Submit

- Make sure the code compiles and loads cleanly in the driver.
- If your change touches a documented system, update the relevant page under this wiki.
- Run the unit tests for any area you changed (see the `testing` skill and the `runtests` wizard command).
