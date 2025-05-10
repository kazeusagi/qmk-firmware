FROM python:3-slim-bookworm

RUN apt-get update && apt-get install -y \
  # curl \
  # unzip \
  # jq \
  git \
  sudo \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

# non-root-userの追加
ARG USER_NAME=user
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USER_NAME \
  && useradd --gid $USER_GID --uid $USER_UID -m $USER_NAME -s /bin/bash \
  && echo $USER_NAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USER_NAME \
  && chmod 0440 /etc/sudoers.d/$USER_NAME

# non-root-userに切り替え
USER $USER_NAME

# QMKのインストール
RUN sudo python3 -m pip install qmk
RUN qmk setup -y

# QMKの設定
ARG KEYBOARD
ARG KEYMAP
RUN qmk config user.keyboard=${KEYBOARD}
RUN qmk config user.keymap=${KEYMAP}
