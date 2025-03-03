# Changelog
All notable changes to this tsn ref sw  will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

NOTE: The ChangeLog is only included in the release starting v0.8.22.
For prior version, please refer to the tag commit message. Sorry guys.

## [0.8.22] - 2022-02-09
- Support for kernel 5.1x in the scripts
- Changes json config to support EHL 2-port opcua functionalities
  for kernel 5.10 and above.
- Configuration changes for vs1 for EHl kernel 5.10 and above

## [0.8.23] - 2022-02-18
- missing configuration for rpl opcua-pkt1 is added.
- vs1x rpl default configuration is changed.
- added check for gnuplot availability.
- check for log folder availability. Force creation if missing.

## [0.8.24] - 2022-03-08
- TBS calculation (avg and stddev)
- Additional column for U2U latency stddev
- GCL/taprio configuration printout
- timesync stat printout upon ptp4l/phc2sys logs availability
- XDP opcua queue change to q3 for adl2 and rpl2
